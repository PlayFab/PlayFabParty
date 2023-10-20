package com.microsoft.playfab.partysample.adapter;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.microsoft.playfab.partysample.demo.R;
import com.microsoft.playfab.partysample.model.ChatMember;
import com.microsoft.playfab.partysample.sdk.MessageManager;

import java.util.Iterator;
import java.util.List;

public class MemberAdapter extends RecyclerView.Adapter<MemberAdapter.ViewHolder> {

    List<ChatMember> members;

    public MemberAdapter(List<ChatMember> members) {
        this.members = members;
    }

    @NonNull
    @Override
    public MemberAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        Log.d("member adapter","onCreateViewHolder");
        View view = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.chat_member_item, viewGroup, false);
        final ViewHolder viewHolder = new ViewHolder(view);
        return viewHolder;
    }

    @Override
    public void onBindViewHolder(@NonNull MemberAdapter.ViewHolder viewHolder, int i) {
        Log.d("member adapter","onBindViewHolder");
        final ChatMember member = members.get(i);
        viewHolder.memberNameView.setText(member.getName());
        viewHolder.voiceIconView.getDrawable().setLevel(member.isTalking() ? 1 : 0);

        if (member.isCurrent()) {
            viewHolder.leaveBtn.setVisibility(View.VISIBLE);

            viewHolder.leaveBtn.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    MessageManager.getInstance().sendLeaveMessage();
                }
            });
        } else {
            viewHolder.leaveBtn.setVisibility(View.GONE);
        }
    }

    @Override
    public int getItemCount() {
        return members != null ? members.size() : 0;
    }

    static class ViewHolder extends RecyclerView.ViewHolder {
        ImageView voiceIconView;
        TextView memberNameView;
        Button leaveBtn;

        public ViewHolder(View view) {
            super(view);
            voiceIconView = view.findViewById(R.id.imageView);
            memberNameView = view.findViewById(R.id.nameTextView1);
            leaveBtn = view.findViewById(R.id.buttonLeave);
        }

    }

    public void addMember(String id, String name) {
        synchronized (members) {
            for (ChatMember member : members) {
                if (id.equals(member.getId())) {
                    return;
                }
            }

            ChatMember member = new ChatMember();
            member.setId(id);
            member.setName(name);
            members.add(member);
        }

        this.notifyDataSetChanged();
    }

    public void removeMember(String id) {
        synchronized (members) {
            Iterator<ChatMember> iterator = members.iterator();
            while (iterator.hasNext()) {
                ChatMember member = iterator.next();
                if (id.equals(member.getId())) {
                    iterator.remove();
                }
            }
        }

        this.notifyDataSetChanged();
    }

    public void updateMemberState(String id, String state) {
        ChatMember member = getMemberById(id);
        if (member == null) {
            return;
        }

        switch (state) {
            case ChatMember.STATE_MUTED: {
                member.setMute(true);
                member.setTalking(false);
                break;
            }
            case ChatMember.STATE_SILENT: {
                member.setTalking(false);
                break;
            }
            case ChatMember.STATE_TALKING: {
                member.setMute(false);
                member.setTalking(true);
            }
        }
        this.notifyDataSetChanged();
    }

    public ChatMember getMemberById(String id) {
        synchronized (members) {
            for (ChatMember member : members) {
                if (id.equals(member.getId())) {
                    return member;
                }
            }
        }

        return null;
    }

    public void clear() {
        synchronized (members) {
            ChatMember member = members.get(0);
            member.setTalking(false);
            members.clear();
            members.add(member);
        }
        this.notifyDataSetChanged();
    }
}
